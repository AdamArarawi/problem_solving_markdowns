import sys

input = sys.stdin.readline
output = sys.stdout.write

nums = [-2, 0, 0, 2, 2]
nums.sort()
result = []

n = len(nums)

for i in range(n):
    if i > 0 and nums[i] == nums[i - 1]:
        continue

    l = i + 1
    r = n - 1

    while l < r:
        s = nums[i] + nums[l] + nums[r]

        if s == 0:
            result.append([nums[i], nums[l], nums[r]])

            l += 1
            r -= 1

            # تجاهل التكرارات
            while l < r and nums[l] == nums[l - 1]:
                l += 1
            while l < r and nums[r] == nums[r + 1]:
                r -= 1

        elif s > 0:
            r -= 1
        else:
            l += 1

print(result)


