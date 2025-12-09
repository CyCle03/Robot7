example_dict = {
    "키A" : "값A",
    "키B" : "값B",
    "키C" : "값C"
}

for key in example_dict:
    print("{} : {}".format(example_dict[key], example_dict.get(key)))
    #존재하지 않는 키가 있을 시 에러가 발생할 수 있다.
print()

for key, value in example_dict.items():
    print("{} : {}".format(key, value))

