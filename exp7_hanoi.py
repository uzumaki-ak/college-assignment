def hanoi(n, source, target, auxiliary):
    if n == 1:
        print(f"  Move disk 1: {source} --> {target}")
        return
    hanoi(n-1, source, auxiliary, target)
    print(f"  Move disk {n}: {source} --> {target}")
    hanoi(n-1, auxiliary, target, source)

n = 3
print(f"Tower of Hanoi with {n} disks:")
hanoi(n, 'A', 'C', 'B')
print(f"\nTotal moves: {2**n - 1}")
