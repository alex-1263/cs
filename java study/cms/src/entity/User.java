package entity;

public class User {
    private String uid;
    private String username;
    private String password;
    private String email;
    private String level;
    private String deptcode;

    public void user() {
    }

    public void user(String uid, String username, String password, String email, String lever, String deptcode) {
        this.uid=uid;
        this.username=username;
        this.password=password;
        this.email=email;
        this.level=level;
        this.deptcode=deptcode;
    }
    public String getUid(){
        return uid;
    }
    public  void setUid(String uid){
        this.uid=uid;
    }
    public String getUsername(){
        return  username;
    }
    public void setUsername(String username) {
        this.username=username;
    }
    public String getPassword(){
        return password;
    }
    public  void setPassword(String password){
        this.password=password;
    }
    public String getEmail(){
        return  email;
    }
    public void setDeptcode(String deptcode) {
        this.deptcode = deptcode;
    }
    public  String getLevel(){
        return  level;
    }
    public void setEmail(String email) {
        this.email = email;
    }
    public String getDeptcode(){
        return deptcode;
    }
    public void setLever(String lever) {
        this.level = lever;
    }

    public  String toString(){
        return  "uid'"+uid+'\''+
                "|username='"+username+'\''+
                "|password='"+password+'\''+
                "|email='"+email+'\''+
                "|lever='"+level+'\''+
                "|deptcode+'"+deptcode+'\''+
                '}';
        }
    }


