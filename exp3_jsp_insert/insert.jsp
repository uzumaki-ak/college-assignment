<%@ page import="java.sql.*" %>
<%
String r=request.getParameter("roll_no"),n=request.getParameter("name"),b=request.getParameter("branch");
try{
 Class.forName("org.postgresql.Driver");
 try(Connection c=DriverManager.getConnection("jdbc:postgresql://localhost:5432/practicaldb","postgres","postgres");
     PreparedStatement p=c.prepareStatement("insert into student(roll_no,name,branch) values(?,?,?)")){
  p.setInt(1,Integer.parseInt(r)); p.setString(2,n); p.setString(3,b); p.executeUpdate();
  out.print("Record Inserted Successfully!");
 }
}catch(Exception e){ out.print("Error: "+e.getMessage()); }
%>
<br><a href="form.jsp">Back</a>
