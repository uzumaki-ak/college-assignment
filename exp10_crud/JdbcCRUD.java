import java.sql.*;

public class JdbcCRUD {

    static final String URL  = "jdbc:postgresql://localhost:5432/practicaldb";
    static final String USER = "postgres";
    static final String PASS = "postgres"; // change to your password

    static Connection getConnection() throws Exception {
        Class.forName("org.postgresql.Driver");
        return DriverManager.getConnection(URL, USER, PASS);
    }

    // CREATE
    static void insert(int rollNo, String name, String branch) throws Exception {
        String sql = "INSERT INTO student(roll_no, name, branch) VALUES(?,?,?)";
        try (Connection con = getConnection();
             PreparedStatement ps = con.prepareStatement(sql)) {
            ps.setInt(1, rollNo);
            ps.setString(2, name);
            ps.setString(3, branch);
            int rows = ps.executeUpdate();
            System.out.println("INSERT: " + rows + " row(s) affected.");
        }
    }

    // READ ALL
    static void readAll() throws Exception {
        String sql = "SELECT * FROM student ORDER BY id";
        try (Connection con = getConnection();
             Statement st = con.createStatement();
             ResultSet rs = st.executeQuery(sql)) {
            System.out.println("\n--- All Students ---");
            System.out.printf("%-5s %-8s %-20s %-10s%n", "ID", "Roll No", "Name", "Branch");
            System.out.println("-".repeat(46));
            while (rs.next()) {
                System.out.printf("%-5d %-8d %-20s %-10s%n",
                    rs.getInt("id"), rs.getInt("roll_no"),
                    rs.getString("name"), rs.getString("branch"));
            }
        }
    }

    // UPDATE
    static void update(int rollNo, String newBranch) throws Exception {
        String sql = "UPDATE student SET branch=? WHERE roll_no=?";
        try (Connection con = getConnection();
             PreparedStatement ps = con.prepareStatement(sql)) {
            ps.setString(1, newBranch);
            ps.setInt(2, rollNo);
            int rows = ps.executeUpdate();
            System.out.println("UPDATE: " + rows + " row(s) affected.");
        }
    }

    // DELETE
    static void delete(int rollNo) throws Exception {
        String sql = "DELETE FROM student WHERE roll_no=?";
        try (Connection con = getConnection();
             PreparedStatement ps = con.prepareStatement(sql)) {
            ps.setInt(1, rollNo);
            int rows = ps.executeUpdate();
            System.out.println("DELETE: " + rows + " row(s) affected.");
        }
    }

    public static void main(String[] args) throws Exception {
        System.out.println("=== JDBC CRUD Operations (PostgreSQL) ===\n");

        System.out.println("-- INSERT --");
        insert(301, "Karan Joshi",   "CSE");
        insert(302, "Meera Nair",    "IT");
        insert(303, "Vikram Tiwari", "ECE");
        readAll();

        System.out.println("\n-- UPDATE (Roll 302 -> AIML) --");
        update(302, "AIML");
        readAll();

        System.out.println("\n-- DELETE (Roll 303) --");
        delete(303);
        readAll();
    }
}
