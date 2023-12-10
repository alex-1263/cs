package com.edu.service.bill;

import com.edu.dao.BillMapper;
import com.edu.pojo.Bill;
import org.jboss.logging.Param;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class BillServiceImpl implements BillService {

    @Autowired
    BillMapper billMapper;

    @Override
    public List<Bill> queryBill(String productName, Integer providerId, Integer isPayment) {
        return billMapper.queryBill(productName, providerId, isPayment);
    }

    @Override
    public int addBill(Bill bill) {
        return billMapper.addBill(bill);
    }

    @Override
    public Bill getBillById(String id) {
        return billMapper.getBillById(id);
    }

    @Override
    public int modifyBill(Bill bill) {
        return 0;
    }

}
