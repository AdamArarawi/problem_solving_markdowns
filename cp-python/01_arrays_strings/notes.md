# 01 – Arrays & Strings في Python (نسخة المحترفين)

## 1. الفروقات الخطيرة عن C++

### في C++

```cpp
vector<int> a(n);
```

### في Python

```python
a = [0] * n
```

بس انتبه ⚠️:

```python
a = [[0]*m]*n   # غلط – نفس الذاكرة
```

الصحيح:

```python
a = [[0]*m for _ in range(n)]
```

---

## أهم أدوات السرعة (لازم تحفظهم)

### إدخال سريع

```python
import sys
input = sys.stdin.readline
```

### قراءة أعداد بسرعة

```python
a = list(map(int, input().split()))
```

### طباعة سريعة

```python
sys.stdout.write(str(x) + "\n")
```

---

## حركات Python تنافسية

### 1) Loop ذكي بدل if

```python
# عد كم عدد الأعداد الزوجية
cnt = sum(x % 2 == 0 for x in a)
```

### 2) slicing (قوية جداً)

```python
b = a[::-1]        # عكس
b = a[2:7]         # مقطع
```

### 3) unpacking

```python
x, y = a[0], a[-1]
```

### 4) enumerate بدل index

```python
for i, val in enumerate(a):
    ...
```
