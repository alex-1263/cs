package dao;

import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import entity.User;
import util.DBUtil;

public class UserDao extends DBUtil {
    public List<User> getAllUser() {
        List<User> users = new ArrayList<User>();
        Statement stmt = null;
        ResultSet rs = null;
        String sql = "select * from tb_user";

        try {
            getConnection();
            stmt = conn.createStatement();
            rs = stmt.executeQuery(sql);
            while (rs.next()) {
                User user = new User();
                user.setUid(rs.getString(1));
                user.setUsername(rs.getString(2));
                user.setPassword(rs.getString(3));
                user.setEmail(rs.getString(4));
                user.setLevel(rs.getString(5));
                user.setDeptcode(rs.getString(6));

                users.add(user);
            }

        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        } finally {
            this.closeResource();
        }

        return users;
    }

    public boolean loginUser(String name, String passwd) {
        boolean flag = false;
        ResultSet rs = null;
        String sql = "select * from tb_user where username=? and password=?";
        Object[] params={name, passwd};

        try {
            rs = this.executeSQL(sql, params);
            if (rs.next()){
                flag = true;
            }

        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        } finally {
            this.closeResource();
        }

        return flag;
    }

    public boolean insertUser(User user) {
        boolean flag=false;
        try {
            String sql="insert into tb_user(uid,username,password,email,lever,deptcode) values(?,?,?,?,?,?)";
            Object[] params={user.getUid(), user.getUsername(), user.getPassword(), user.getEmail(), user.getLevel(), user.getDeptcode()};
            int i=this.executeUpdate(sql, params);
            //（4）处理执行结果
            if(i>0){
                System.out.println("插入用户成功！");
            }
            flag=true;
        }finally{
            //释放资源
            this.closeResource();
        }
        return flag;
    }

    public boolean deleteUser(int id) {
        boolean flag=false;
        try {
            String sql = "delete from  tb_user where uid=?";
            Object[] params={id};
            int i=this.executeUpdate(sql, params);
            //（4）处理执行结果
            if(i>0){
                System.out.println("删除用户信息成功！");
            }
            flag=true;
        }  finally {
            //释放资源
            this.closeResource();
        }
        return flag;
    }

    public boolean updateUser(User user) {
        boolean flag=false;
        try {
            String sql = "update tb_user set username=?, password=? , email=?, lever=?"
                    +",deptcode=? where uid=?";
            Object[] params={user.getUsername(), user.getPassword(), user.getEmail(), user.getLevel(), user.getDeptcode()};
            int i=this.executeUpdate(sql, params);
            //（4）处理执行结果
            if(i>0){
                System.out.println("修改用户信息成功！");
            }
            flag=true;
        }  finally {
            //释放资源
            this.closeResource();
        }
        return flag;
    }
}