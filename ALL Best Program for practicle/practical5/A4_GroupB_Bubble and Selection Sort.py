def selection_sort(mark):
    for i in range(len(mark)):
        minimum_index = i
        for j in range(i + 1, len(mark)):
            if mark[minimum_index] > mark[j]:
                minimum_index = j
        mark[i], mark[minimum_index] = mark[minimum_index],  mark[i]
    print("\nMarks of students in ascending order using Selection Sort :")
    for i in range(len(mark)):
        print(mark[i], sep="\n")


def bubble_sort(mark):
    length = len(mark)
    for i in range(length-1):
        for j in range(0, length-i-1):
            if mark[j] > mark[j+1]:
                mark[j], mark[j+1] = mark[j+1], mark[j]
    print("\nMarks of students in ascending order using Bubble Sort :")
    for i in range(len(mark)):
        print(mark[i], sep="\n")


def top_five_marks(mark):
    print("\nTop five marks are :")
    print(*mark[:-6:-1], sep="\n")


n = int(input("Enter the no of students :"))
marks = []
print("Enter marks of", n, "students :")
for a in range(0, n):
    marks_input = float(input())
    marks.append(marks_input)


flag = 1
while flag == 1:
    print("\nSelect any option you want :")
    print("1] Selection Sort.")
    print("2] Bubble Sort.")
    print("3] Top 5 scores.")
    print("4] Exit.")
    option = int(input("\nEnter Option :"))

    if option == 1:
        selection_sort(marks)
        con = input("\nDo you want to close (y/n) :")
        if con == "y":
            break
        else:
            flag = 1

    elif option == 2:
        bubble_sort(marks)
        con = input("\nDo you want to close (y/n) :")
        if con == "y":
            break
        else:
            flag = 1

    elif option == 3:
        top_five_marks(marks)
        con = input("\nDo you want to close (y/n) :")
        if con == "y":
            break
        else:
            flag = 1

    elif option == 4:
        flag = 0

    else:
        print("\nPlease select correct option !!")
        con = input("\nDo you want to close (y/n) :")
        if con == "y":
            break
        else:
            flag = 1

