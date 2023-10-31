package util;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
public class DBUtil {
    protected Connection conn;
    protected PreparedStatement ps;
    protected Statement stmt;
    protected ResultSet rs;

    public boolean getConnection(){
        String user="root";
        String password="123456";
        String url="jdbc:mysql://localhost:3306/cms?characterEncoding=utf8";

        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection(url,user,password);
            if(null!=conn){
                return true;
            }
        }catch (Exception e){
            e.printStackTrace();
        }
        return false;
    }
    public boolean closeResource(){
        if(rs!=null){
            try{
                rs.close();

            }catch (SQLException e){
                e.printStackTrace();
                return false;
            }
        }
        if(ps!=null){
            try{
                ps.close();
            }catch (SQLException e){
                e.printStackTrace();
                return false;
            }
        }
        if(stmt!=null){
            try{
                stmt.close();
            }catch (SQLException e){
                e.printStackTrace();
                return false;
            }
        }
        if(conn!=null){
            try{
                conn.close();
            }catch(SQLException e){
                e.printStackTrace();
                return false;
            }
        }
        return true;
    }
    public int executeUpdate(String sql, Object[] params) {
        int updateRows = 0;
        getConnection();
        try {
            ps = conn.prepareStatement(sql);
            // 填充占位符
            for (int i = 0; i < params.length; i++) {
                ps.setObject(i + 1, params[i]);
            }
            updateRows = ps.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return updateRows;
    }

    // 查询
    public ResultSet executeSQL(String sql, Object[] params) {
        getConnection();
        try {
            ps = conn.prepareStatement(sql);
            // 填充占位符
            for (int i = 0; i < params.length; i++) {
                ps.setObject(i + 1, params[i]);
            }
            rs = ps.executeQuery();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return rs;
    }
}