package com.edu.dao;

import com.edu.pojo.Provider;

import java.util.List;

public interface ProviderMapper {
    public List<Provider> queryProvider();

    /**
     * 供应商管理
     * @return
     */
    public List<Provider> suppliermanage();
}
