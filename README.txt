================================================================
  JAVA PRACTICALS - PostgreSQL Setup (Windows, Java 17)
================================================================

WHAT YOU HAVE:
  Java 17         ✅
  Tomcat 9        ✅  (apache-tomcat-9.0.111)

WHAT YOU NEED:
================================================================

1. PostgreSQL (if not installed)
   Download: https://www.postgresql.org/download/windows/
   - Click "Download the installer" (EDB installer)
   - During install:
       * Set password for user "postgres" -> use "postgres" (simple)
       * Port: 5432 (default, keep it)
       * Uncheck "Stack Builder" at end
   - After install, open "SQL Shell (psql)" from Start Menu

2. PostgreSQL JDBC Driver JAR (just one file needed!)
   Download: https://jdbc.postgresql.org/download/
   - Download: postgresql-42.x.x.jar
   - Save it somewhere easy e.g. C:\jars\postgresql.jar

================================================================
SETUP DATABASE (run in SQL Shell / psql):
================================================================

  CREATE DATABASE practicaldb;
  \c practicaldb

  CREATE TABLE student (
      id       SERIAL PRIMARY KEY,
      roll_no  INT,
      name     VARCHAR(100),
      branch   VARCHAR(50)
  );

  -- For exp 9 (Feedback):
  CREATE TABLE feedback (
      id           SERIAL PRIMARY KEY,
      visitor_name VARCHAR(100),
      email        VARCHAR(100),
      message      TEXT,
      rating       INT,
      submitted_at TIMESTAMP DEFAULT NOW()
  );

================================================================
HOW TO RUN EXP 1 & 10 (Standalone JDBC):
================================================================

  > javac -cp .;C:\jars\postgresql.jar JdbcConnection.java
  > java  -cp .;C:\jars\postgresql.jar JdbcConnection

  (replace C:\jars\postgresql.jar with actual path of your JAR)

================================================================
HOW TO RUN EXP 2-7 (JSP / Servlet using Tomcat 9):
================================================================

  Your Tomcat is at: apache-tomcat-9.0.111

  Step 1: Copy postgresql.jar to:
          apache-tomcat-9.0.111\lib\

  Step 2: Create app folder:
          apache-tomcat-9.0.111\webapps\myapp\

  Step 3: Put .jsp files directly in:
          apache-tomcat-9.0.111\webapps\myapp\

  Step 4: Start Tomcat:
          apache-tomcat-9.0.111\bin\startup.bat

  Step 5: Open browser:
          http://localhost:8080/myapp/index.jsp

================================================================
EXPECTED OUTPUTS:
================================================================

EXP 1:
  Connection Successful!
  Database: practicaldb
  Driver:   PostgreSQL JDBC Driver
  URL:      jdbc:postgresql://localhost:5432/practicaldb
  Connection Closed.

EXP 10:
  === JDBC CRUD Operations (PostgreSQL) ===
  -- INSERT --
  INSERT: 1 row(s) affected.
  --- All Students ---
  ID    Roll No  Name                 Branch
  ----------------------------------------------
  1     301      Karan Joshi          CSE
  2     302      Meera Nair           IT
  3     303      Vikram Tiwari        ECE
  -- UPDATE (Roll 302 -> AIML) --
  UPDATE: 1 row(s) affected.
  -- DELETE (Roll 303) --
  DELETE: 1 row(s) affected.

================================================================
