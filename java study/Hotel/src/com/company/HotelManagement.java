package com.company;

import java.sql.*;

public class HotelManagement {
    private Connection conn = null;
    private Statement stmt = null;

    // 连接数据库
    public void connectDB() {
        try {
            // 加载MySQL的JDBC驱动程序
            Class.forName("com.mysql.jdbc.Driver");

            // 连接MySQL数据库
            conn = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/hotel_management?useSSL=false",
                    "root",
                    "123456"
            );

            stmt = conn.createStatement();
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    // 关闭数据库连接
    public void closeDB() {
        try {
            if (stmt != null) {
                stmt.close();
            }
            if (conn != null) {
                conn.close();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    // 添加记录
    public void insertData() {
        try {
            String sql = "INSERT INTO room(room_id, room_type, room_price, room_status) VALUES(101, '单人间', 300, '空闲')";
            stmt.executeUpdate(sql);
            System.out.println("插入记录成功");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    // 删除记录
    public void deleteData() {
        try {
            String sql = "DELETE FROM room WHERE room_id=101";
            stmt.executeUpdate(sql);
            System.out.println("删除记录成功");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    // 修改记录
    public void updateData() {
        try {
            String sql = "UPDATE room SET room_price=350 WHERE room_id=102";
            stmt.executeUpdate(sql);
            System.out.println("更新记录成功");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    // 查询记录
    public void queryData() {
        try {
            String sql = "SELECT * FROM room";
            ResultSet rs = stmt.executeQuery(sql);
            while (rs.next()) {
                System.out.println("room_id: " + rs.getInt("room_id"));
                System.out.println("room_type: " + rs.getString("room_type"));
                System.out.println("room_price: " + rs.getInt("room_price"));
                System.out.println("room_status: " + rs.getString("room_status"));
                System.out.println("------------------------");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    // 测试程序
    public static void main(String[] args) {
        HotelManagement hm = new HotelManagement();
        hm.connectDB();
        hm.insertData();
        hm.deleteData();
        hm.updateData();
        hm.queryData();
        hm.closeDB();
    }
}
