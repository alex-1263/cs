import com.edu.pojo.Provider;
import com.edu.service.provider.ProviderServiceImpl;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import java.util.List;
@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = {"classpath:applicationContext.xml"})//加载spring Ioc容器
public class ProviderServiceTest {

    @Autowired
    ProviderServiceImpl providerServiceImpl;
    @Test
    public void testGetAll(){
        List<Provider> list=providerServiceImpl.getProviderList("","");
        for (Provider p:list) {
            System.out.println(p);
        }
        System.out.println(providerServiceImpl.getProviderById("12"));
    }
    @Test
    public void testaddProvider(){
     Provider provider=new Provider();
     provider.setProName("金龙鱼大豆油");
     providerServiceImpl.add(provider);
    }

}
