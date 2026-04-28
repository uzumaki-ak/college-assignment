import java.io.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/validate")
public class UserValidationServlet extends HttpServlet {
    protected void doPost(HttpServletRequest req, HttpServletResponse res) throws IOException {
        String u=req.getParameter("user"), p=req.getParameter("pass");
        res.setContentType("text/html");
        res.getWriter().print(("admin".equals(u) && "1234".equals(p)) ? "Valid User" : "Invalid User");
    }
}
