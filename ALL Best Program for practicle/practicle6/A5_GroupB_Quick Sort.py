def percentage_partition(per, start, end):
    pivot = per[start]
    lower = start + 1
    upper = end

    while True:
        while lower <= upper and per[lower] <= pivot:
            lower += 1

        while lower <= upper and per[upper] >= pivot:
            upper -= 1

        if lower <= upper:
            per[lower], per[upper] = per[upper], per[lower]

        else:
            break

    per[start], per[upper] = per[upper], per[start]

    return upper


def quick_sort(per, start, end):
    while start < end:
        partition = percentage_partition(per, start, end)
        quick_sort(per, start, partition-1)
        quick_sort(per, partition+1, end)
        return per


def top_five_percentage(per):
    print("\nTop five marks are :")
    print(*per[:-6:-1], sep="\n")


n = int(input("Enter the no of students :"))
percentage = []
print("Enter marks of", n, "students :")
for a in range(0, n):
    percentage_input = float(input())
    percentage.append(percentage_input)


print("\nPercentage of students after sorting :", quick_sort(percentage, 0, len(percentage)-1))
top_five_percentage(percentage)

