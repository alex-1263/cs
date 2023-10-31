package com.digital.dao;

import com.digital.beans.Goods;

import java.util.List;

public interface GoodsDao {
    public List<Goods> getGoodsList();

    Goods getInstance();

    public Goods getInstance(Goods goods);

    Goods getGoodsById();

    Goods getGoodsById(Goods goods);
}
