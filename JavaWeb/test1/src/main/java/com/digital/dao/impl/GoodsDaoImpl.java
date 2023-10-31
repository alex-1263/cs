package com.digital.dao.impl;

import com.digital.beans.Goods;
import com.digital.dao.BaseDao;
import com.digital.dao.GoodsDao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class GoodsDaoImpl extends BaseDao implements GoodsDao {
    private PreparedStatement pStatement;
    private ResultSet rSet;

    @Override
    public List<Goods> getGoodsList() {
        List<Goods> list=new ArrayList<Goods>();
        try{
            getConnection();
            String sql="SELECT * FROM goods";
            pStatement=connection.prepareStatement(sql);
            rSet= preparedStatement.executeQuery();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return list;
    }

    @Override
    public Goods getInstance(Goods goods) {
        return null;
    }

    @Override
    public Goods getGoodsById(Goods goods) {
        return null;
    }
}
