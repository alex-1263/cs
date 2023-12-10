package com.edu.service.provider;

import com.edu.pojo.Provider;

import java.util.List;

public interface ProviderService {
    public List<Provider> queryProvider();

    /**
     * 供应商管理
     * @return
     */
    public List<Provider> suppliermanage();
}
