package com.edu.dao;

import com.edu.pojo.Bill;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface BillDao {
    public int add(Bill bill);

    public List<Bill> getBillList(Bill bill);

    public int deleteBillById(String delId);

    public Bill getBillById(String id);

    public int modify(Bill bill);

    public int getBillCountByProviderId(String providerId);

}
