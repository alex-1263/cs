package com.digital.dao;

import com.digital.beans.Goods;

import java.util.List;

public interface GoodsDao {
    public List<Goods> getGoodsList();
    public Goods getInstance(Goods goods);
    Goods getGoodsById(Goods goods);
}
