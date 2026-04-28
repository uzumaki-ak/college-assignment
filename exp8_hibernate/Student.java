import jakarta.persistence.*;

@Entity
@Table(name="student")
public class Student {
    @Id @GeneratedValue(strategy=GenerationType.IDENTITY) private int id;
    @Column(name="roll_no") private int rollNo;
    private String name, branch;
    public Student() {}
    public Student(int rollNo, String name, String branch) { this.rollNo=rollNo; this.name=name; this.branch=branch; }
}
