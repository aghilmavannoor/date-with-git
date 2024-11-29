import random
num_variables = 50000
min_value = 0
max_value = 50000

# Generate random variables and save to file
with open("random_variables.txt", "w") as file:
    for _ in range(num_variables):
        file.write(str(random.randint(min_value, max_value)) + "\n")

print("Random variables generated and saved to random_variables.txt")