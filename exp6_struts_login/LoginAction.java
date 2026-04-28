public class LoginAction {
    private String user, pass;
    public String execute() { return ("admin".equals(user) && "1234".equals(pass)) ? "success" : "error"; }
    public String getUser() { return user; }
    public void setUser(String user) { this.user = user; }
    public String getPass() { return pass; }
    public void setPass(String pass) { this.pass = pass; }
}
