package com.edu.service.provider;

import com.edu.dao.ProviderDao;
import com.edu.pojo.Provider;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Transactional(propagation = Propagation.REQUIRED, rollbackForClassName = "Exception")
@Service
public class ProviderServiceImpl implements ProviderService {

    @Autowired
    private ProviderDao providerDao;

    public ProviderServiceImpl() {
    }

    public boolean add(Provider provider) {
        int j = providerDao.add(provider);
//		int a=1/0;
        return j > 0 ? true : false;
    }

    public List<Provider> getProviderList(String proName, String proCode) {

        return providerDao.getAllProvider(proName, proCode);
    }

    public int deleteProviderById(String delId) {
        return providerDao.delete(delId);
    }

    public Provider getProviderById(String id) {
        return providerDao.getProviderById(id);
    }

    public boolean modify(Provider provider) {
        return providerDao.modify(provider) > 0 ? true : false;
    }

}
