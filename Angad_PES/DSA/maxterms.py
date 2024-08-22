def minmax(a, b):
    product = []
    for i in range(len(a)):
        product.append(max(a)*max(b))
        a[i] = a[i]+b[i]
        b[i] = a[i]-b[i]
        a[i] = a[i]-b[i]
        product.append(max(a)*max(b))
    return min(product)
a = [1,4,6,5,1,5]
b = [3,2,3,2,2,2]
result = minmax(a, b)
print(result)