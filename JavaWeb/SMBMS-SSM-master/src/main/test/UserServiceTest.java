import com.edu.pojo.User;
import com.edu.service.user.UserService;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;


@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = "classpath:applicationContext.xml")
public class UserServiceTest {
    @Autowired
    UserService userService;
    @Test
    public void testUserLogin(){
        User user=userService.login("admin","1234567");
    }
     @Test
    public void testGetUserById(){
        User user=userService.getUserById("5");
         System.out.println(user.getAge());
    }
    @Test
    public void testaddUser(){
        User user=new User();
        user.setUserName("123");
//       userService.login("12","12")
        userService.add(user);

    }
}
