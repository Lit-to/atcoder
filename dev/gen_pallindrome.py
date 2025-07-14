def fill_digits(pallindromes,arr, n, i, odd):
    if i == n:
        r = "".join(arr)
        r += r[::-1][odd:]
        pallindromes.add(r)
    else:
        for j in range(0, len(element)):
            arr[i] = str(j)
            fill_digits(arr, n, i + 1, odd)

def fill_digits_int(pallindromes,arr, n, i, odd):
    if i == n:
        r = "".join(arr)
        r += r[::-1][odd:]
        pallindromes.add(int(r))
    else:
        for j in range(0 + (i == 0), len(element)):
            arr[i] = str(j)
            fill_digits(arr, n, i + 1, odd)

def gen_pallindrome(n: int, element: list):
    pallindromes = set()
    fill_digits(pallindromes,[""] * (n // 2 + n % 2), n // 2 + n % 2, 0, n % 2)
    return sorted(list(pallindromes))

def gen_num(n:int):
    return gen_pallindrome(n, ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"])
