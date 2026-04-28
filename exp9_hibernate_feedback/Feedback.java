import java.time.LocalDateTime;
import jakarta.persistence.*;

@Entity
@Table(name="feedback")
public class Feedback {
    @Id @GeneratedValue(strategy=GenerationType.IDENTITY) private int id;
    @Column(name="visitor_name") private String visitorName;
    private String email, message;
    private int rating;
    @Column(name="submitted_at") private LocalDateTime submittedAt;
    public Feedback() {}
    public Feedback(String visitorName, String email, String message, int rating) {
        this.visitorName=visitorName; this.email=email; this.message=message; this.rating=rating; this.submittedAt=LocalDateTime.now();
    }
}
