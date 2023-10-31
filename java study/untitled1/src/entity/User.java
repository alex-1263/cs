package entity;

public class User {
    private String uid;
    private String username;
    private String password;
    private String email;
    private String level;
    private String deptcode;

    public void setUid(String uid) {
        this.uid = uid;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setLevel(String level) {
        this.level = level;
    }

    public void setDeptcode(String deptcode) {
        this.deptcode = deptcode;
    }

    public String getUid() {
        return uid;
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }

    public String getEmail() {
        return email;
    }

    public String getLevel() {
        return level;
    }

    public String getDeptcode() {
        return deptcode;
    }

    @Override
    public String toString() {
        return "User{" +
                "uid='" + uid + '\'' +
                ", username='" + username + '\'' +
                ", password='" + password + '\'' +
                ", email='" + email + '\'' +
                ", level='" + level + '\'' +
                ", deptcode='" + deptcode + '\'' +
                '}';
    }
}