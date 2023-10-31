package com.company;

import java.sql.*;

public class JdbcDemo {
    static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
    static final String DB_URL = "jdbc:mysql://localhost:3306/drugstore";
    static final String USER = "root";
    static final String PASS = "123456";

    public static void main(String[] args) {
        Connection conn = null;
        Statement stmt = null;
        try {
            // 注册 JDBC 驱动
            Class.forName(JDBC_DRIVER);

            // 打开链接
            System.out.println("连接数据库...");
            conn = DriverManager.getConnection(DB_URL, USER, PASS);

            // 执行增删查改操作
            stmt = conn.createStatement();

            // 增加一条药品信息
            String sql = "INSERT INTO drug VALUES (9, '阿莫西林', '治疗感染','浙江双成药业有限公司', 20)";
            stmt.executeUpdate(sql);

            // 删除一条药品信息
            sql = "DELETE FROM drug WHERE DrugID = 9";
            stmt.executeUpdate(sql);

            // 修改一条订单信息
            sql = "UPDATE orderinfo SET Quantity = 5 WHERE OrderID = 3";
            stmt.executeUpdate(sql);

            // 查询所有药品信息
            sql = "SELECT * FROM drug";
            ResultSet rs = stmt.executeQuery(sql);

            // 输出查询结果
            while (rs.next()) {
                int id = rs.getInt("DrugID");
                String name = rs.getString("DrugName");
                String desc = rs.getString("Drugtype");
                int price = rs.getInt("Price");
                System.out.println("DrugID: " + id + ", DrugName: " + name + ", Prescription: " + desc + ", Price: " + price);
            }

            // 完成所有操作，关闭资源
            rs.close();
            stmt.close();
            conn.close();
        } catch (SQLException se) {
            // 处理 JDBC 错误
            se.printStackTrace();
        } catch (Exception e) {
            // 处理 Class.forName 错误
            e.printStackTrace();
        } finally {
            // 关闭资源
            try {
                if (stmt != null)
                    stmt.close();
            } catch (SQLException se2) {
            }
            try {
                if (conn != null)
                    conn.close();
            } catch (SQLException se) {
                se.printStackTrace();
            }
        }
        System.out.println("Goodbye!");
    }
}
