package com.edu.service.bill;

import com.edu.dao.BillDao;
import com.edu.pojo.Bill;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Transactional(propagation = Propagation.REQUIRED, rollbackForClassName = "Exception")
@Service
public class BillServiceImpl implements BillService {

    @Autowired
    private BillDao billDao;

    public boolean add(Bill bill) {
        return billDao.add(bill) >= 1 ? true : false;
    }

    public List<Bill> getBillList(Bill bill) {
        return billDao.getBillList(bill);
    }

    public boolean deleteBillById(String delId) {
        return billDao.deleteBillById(delId) >= 1 ? true : false;
    }

    public Bill getBillById(String id) {
        return billDao.getBillById(id);
    }

    public boolean modify(Bill bill) {
        return billDao.modify(bill) >= 1 ? true : false;
    }
}
