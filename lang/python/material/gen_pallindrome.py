def gen_pallindrome(n: int, element: list) -> list:
    """
    elementの中からn個を選び作れる回文を列挙する。

    Args:
        -  n (int): 選ぶ個数
        -  element (list): 配列

    Returns:
        -  list: 作った回文
    """
    pallindromes = set()
    fill_digits(
        pallindromes, element, [""] * (n // 2 + n % 2), n // 2 + n % 2, 0, n % 2
    )
    return sorted(list(pallindromes))

def fill_digits(
    pallindromes: set, elements: list, arr: list, n: int, i: int, is_odd: bool
) -> list:
    """値を埋める

    Args:
        -  pallindromes (set): 使った文字集合
        -  elements (list): 作り途中の配列
        -  arr (list): ? 
        -  n (int): ?
        -  i (int): ?
        -  is_odd (bool): ?

    Returns:
        -  list: _description_
    """
    if i == n:
        r = "".join(arr)
        r += r[::-1][is_odd:]
        pallindromes.add(r)
    else:
        for j in range(0, len(elements)):
            arr[i] = elements[j]
            fill_digits(pallindromes, elements, arr, n, i + 1, is_odd)
