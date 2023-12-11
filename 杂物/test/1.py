class Memory:
    def __init__(self, capacity):
        self.capacity = capacity
        self.pages = []  # 存储内存页面

    def page_fault(self, page):
        pass  # 在子类中实现具体的页面置换算法

    def print_stats(self, page_faults):
        pass  # 在子类中实现具体的统计输出

class FIFO(Memory):
    def __init__(self, capacity):
        super().__init__(capacity)

    def page_fault(self, page):
        # FIFO页面置换算法实现
        if len(self.pages) < self.capacity:
            # 内存未满，直接添加页面
            self.pages.append(page)
        else:
            # 内存已满，先进先出，移除最早进入的页面，添加新页面
            self.pages.pop(0)
            self.pages.append(page)

    def print_stats(self, page_faults):
        print("FIFO缺页次数:", page_faults)

class LRU(Memory):
    def __init__(self, capacity):
        super().__init__(capacity)

    def page_fault(self, page):
        # LRU页面置换算法实现
        if page in self.pages:
            # 页面已存在，移除原位置，后续再添加到末尾表示最近使用
            self.pages.remove(page)
        elif len(self.pages) >= self.capacity:
            # 内存已满，移除最近最少使用的页面，再添加新页面
            self.pages.pop(0)
        self.pages.append(page)

    def print_stats(self, page_faults):
        print("LRU缺页次数:", page_faults)

class OPT(Memory):
    def __init__(self, capacity, future_pages):
        super().__init__(capacity)
        self.future_pages = future_pages  # 未来页面访问序列

    def page_fault(self, page):
        # OPT页面置换算法实现
        if page not in self.pages:
            if len(self.pages) >= self.capacity:
                # 内存已满，计算未来页面访问距离最远的页面，移除并添加新页面
                distances = [self.future_pages.index(p) if p in self.future_pages else float('inf') for p in self.pages]
                idx = distances.index(max(distances))
                self.pages.pop(idx)
            self.pages.append(page)

    def print_stats(self, page_faults):
        print("OPT缺页次数:", page_faults)

def simulate(memory, pages):
    page_faults = 0
    for page in pages:
        if page not in memory.pages:
            # 发生缺页，调用页面置换算法
            memory.page_fault(page)
            page_faults += 1
    memory.print_stats(page_faults)

# 示例用法
if __name__ == '__main__':
    # 页面参考串
    reference_string = [3, 1, 4, 2, 8, 6, 5, 9, 7, 0, 2, 5, 1]
    
    # FIFO算法
    fifo_memory = FIFO(4)
    simulate(fifo_memory, reference_string)    
    
    # LRU算法
    lru_memory = LRU(4)
    simulate(lru_memory, reference_string)    
    
    # OPT算法
    opt_memory = OPT(4, reference_string)
    simulate(opt_memory, reference_string)
