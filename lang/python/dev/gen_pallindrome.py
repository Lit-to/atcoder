def fill_digits(pallindromes,elements,arr, n, i, odd):
    if i == n:
        r = "".join(arr)
        r += r[::-1][odd:]
        pallindromes.add(r)
    else:
        for j in range(0, len(elements)):
            arr[i] = elements[j]
            fill_digits(pallindromes,elements,arr, n, i + 1, odd)

def gen_pallindrome(n: int, element: list):
    pallindromes = set()
    fill_digits(pallindromes,element,[""] * (n // 2 + n % 2), n // 2 + n % 2, 0, n % 2)
    return sorted(list(pallindromes))

def gen_num(n:int):
    return gen_pallindrome(n, ["る", "す", "に","な"])

print(gen_num(8)) 
