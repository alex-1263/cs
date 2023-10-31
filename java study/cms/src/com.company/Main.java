package com.company;
import entity.User;
import java.sql.*;
import dao.UserDao;
import java.util.List;
import java.util.Scanner;
import util.DBUtil;

public class Main {

    public static void main(String[] args) {
        //write your code here
        /*try {
            String url = "jdbc:mysql://localhost:3306/cms";
            String username = "root";
            String password = "123456";

            //1.加载驱动
            Class.forName("com.mysql.jdbc.Driver");
            //2.创建数据库连接
            Connection conn = DriverManager.getConnection(url, username, password);

            if (conn != null) {
                System.out.println("success!");
            } else {
                System.out.println("failed");
            }

            //3.创建执行SQL对象
            Statement stmt=conn.createStatement();
            String sql="select * from tb_user";

            //4.执行SQL语句
            ResultSet rs=stmt.executeQuery(sql);

            //5.解析结果集
            while(rs.next()){
                User user =new User();
                user.setUid(rs.getString(1));
                user.setUsername(rs.getString(2));
                user.setPassword(rs.getString(3));
                user.setDeptcode(rs.getString(4));
                user.setEmail(rs.getString(5));
                System.out.println(user.toString());
            }
            rs.close();
            stmt.close();
            conn.close();
        }

        catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }*/
        UserDao userdao = new UserDao();
        System.out.println("请输入用户名和密码(用逗号分割):");
        Scanner sc = new Scanner(System.in);
        boolean flag = userdao.loginUser("余明杰","133123");
        if (flag){
            System.out.println("登录成功!");
        } else {
            System.out.println("登录失败!");
        }
    }
}
