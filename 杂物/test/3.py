def find_cutting_sites(animal_sequence, disease_sequence):
    cutting_sites = []
    len_animal = len(animal_sequence)
    len_disease = len(disease_sequence)

    for i in range(len_animal - len_disease + 1):
        if animal_sequence[i:i + len_disease] == disease_sequence:
            cutting_sites.append(str(i + 1))

    if cutting_sites:
        return ' '.join(cutting_sites)
    else:
        return '-1'

# 输入动物基因序列和疾病基因序列
animal_sequence = input()
disease_sequence = input()

# 查找裁剪位置并输出结果
result = find_cutting_sites(animal_sequence, disease_sequence)
print(result)
