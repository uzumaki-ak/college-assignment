import java.sql.*;

public class JdbcConnection {
    public static void main(String[] args) {
        String url  = "jdbc:postgresql://localhost:5432/practicaldb";
        String user = "postgres";
        String pass = "postgres";  // change to your PostgreSQL password

        try {
            Class.forName("org.postgresql.Driver");
            Connection con = DriverManager.getConnection(url, user, pass);

            if (con != null) {
                System.out.println("Connection Successful!");
                System.out.println("Database: " + con.getCatalog());
                System.out.println("Driver:   " + con.getMetaData().getDriverName());
                System.out.println("URL:      " + con.getMetaData().getURL());
                con.close();
                System.out.println("Connection Closed.");
            }
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
