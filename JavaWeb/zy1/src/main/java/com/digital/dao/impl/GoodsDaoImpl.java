package com.digital.dao.impl;

import com.digital.beans.Goods;
import com.digital.dao.BaseDao;
import com.digital.dao.GoodsDao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public abstract class GoodsDaoImpl extends BaseDao implements GoodsDao {
    private PreparedStatement pStatement;
    private ResultSet rSet;

    /**
     * @return
     */
    @Override
    public List<Goods> getGoodsList() {
        List<Goods> list = new ArrayList<Goods>();
        try {
            getConnection();
            String sql = "SELECT * FROM goods";
            pStatement = connection.prepareStatement(sql);
            rSet = preparedStatement.executeQuery();
            while (rSet.next()) {
                Goods goods1 = new Goods();
                goods1.setGid(rSet.getInt("gid"));
                goods1.setCode(rSet.getString("code"));
                goods1.setName(rSet.getString("name"));
                goods1.setType(rSet.getString("type"));
                goods1.setPic(rSet.getString("pic"));
                goods1.setNum(rSet.getInt("num"));
                goods1.setPrice(rSet.getString("price"));
                goods1.setSale(rSet.getString("sale"));
                goods1.setIntro(rSet.getString("intro"));
                list.add(goods1);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return list;
    }

    @Override
    public Goods getInstance() {
        return null;
    }

    @Override
    public Goods getInstance(Goods goods) {
        return null;
    }

    @Override
    public Goods getGoodsById() {
        return null;
    }

    @Override
    public Goods getGoodsById(Goods goods) {
        getConnection();
        Goods goods1 = new Goods();
        String sql ="select * from goods where gid = ?";
        try{
            pStatement = connection.prepareStatement(sql);
            pStatement.setInt(1,goods.getGid());
            rSet = pStatement.executeQuery();
            if (rSet.next()){
                goods1.setGid(rSet.getInt("gid"));
                goods1.setCode(rSet.getString("code"));
                goods1.setName(rSet.getString("name"));
                goods1.setType(rSet.getString("type"));
                goods1.setPic(rSet.getString("pic"));
                goods1.setNum(rSet.getInt("num"));
                goods1.setPrice(rSet.getString("price"));
                goods1.setSale(rSet.getString("sale"));
                goods1.setIntro(rSet.getString("intro"));
            }
            return  goods1;
        }catch (SQLException e){
            throw new RuntimeException(e);
        }finally {
            closeResource();
        }

    }
}
