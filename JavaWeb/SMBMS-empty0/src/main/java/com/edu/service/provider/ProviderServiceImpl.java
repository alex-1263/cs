package com.edu.service.provider;

import com.edu.dao.ProviderMapper;
import com.edu.pojo.Provider;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;


@Service
public class ProviderServiceImpl implements ProviderService {
    @Autowired
    ProviderMapper providerMapper;

    @Override
    public List<Provider> queryProvider() {
        return providerMapper.queryProvider();
    }

    /**
     * 供应商管理
     *
     * @return
     */
    @Override
    public List<Provider> suppliermanage() {
        return providerMapper.suppliermanage();
    }

}
