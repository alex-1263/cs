# 示例用法
if __name__ == '__main__':
    # 页面参考串
    reference_string = [1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5]
    
    # FIFO算法
    fifo_memory = FIFO(3)
    simulate(fifo_memory, reference_string)    
    
    # LRU算法
    lru_memory = LRU(3)
    simulate(lru_memory, reference_string)    
    
    # OPT算法
    opt_memory = OPT(3, reference_string)
    simulate(opt_memory, reference_string)
