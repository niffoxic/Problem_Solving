upload_another = int(input())
for i in range(int(input())):
    W, H = (int(x) for x in input().split())
    if W >= upload_another and H >= upload_another and W != H:
        print("CROP IT")
        continue
    elif W < upload_another or H < upload_another:
        print("UPLOAD ANOTHER")
        continue
    elif W == H:
        print("ACCEPTED")
 
