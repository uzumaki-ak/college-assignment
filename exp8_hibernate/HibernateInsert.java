import org.hibernate.*;
import org.hibernate.cfg.Configuration;

public class HibernateInsert {
    public static void main(String[] args) {
        Configuration cfg = new Configuration()
            .setProperty("hibernate.connection.driver_class","org.postgresql.Driver")
            .setProperty("hibernate.connection.url","jdbc:postgresql://127.0.0.1:5432/practicaldb")
            .setProperty("hibernate.connection.username","postgres")
            .setProperty("hibernate.connection.password","postgres")
            .setProperty("hibernate.dialect","org.hibernate.dialect.PostgreSQLDialect")
            .setProperty("hibernate.hbm2ddl.auto","update")
            .setProperty("hibernate.show_sql","true")
            .addAnnotatedClass(Student.class);
        SessionFactory sf = cfg.buildSessionFactory();
        Session s = sf.openSession();
        Transaction t = s.beginTransaction();
        s.persist(new Student(401,"Riya","CSE"));
        t.commit();
        s.close();
        sf.close();
        System.out.println("Data inserted by Hibernate.");
    }
}
