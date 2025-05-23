# This script generates a random SAT problem in CNF format.

#5 2
#0 !1 2
#2 3 !4

def generate_cnf(num_vars, num_clauses):
    import random

    cnf = []
    for _ in range(num_clauses):
        clause = set()
        while len(clause) < 3:  # Each clause should have exactly 3 literals
            var = str(random.randint(0, num_vars - 1))
            if random.choice([True, False]):
                var = "!" + var  # Negate the variable with a 50% chance
            clause.add(var)
        cnf.append(list(clause))

    return cnf

def write_cnf_to_file(num_vars, num_clauses, cnf, filename):
    with open(filename, 'w') as f:
        f.write(f"{num_vars} {num_clauses}\n")
        for clause in cnf:
            f.write(" ".join(map(str, clause)) + "\n")

if __name__ == "__main__":
    import sys
    import os
    num_vars = int(sys.argv[1])
    num_clauses = int(sys.argv[2])
    num_files = int(sys.argv[3])
    directory = sys.argv[4]
    os.makedirs(directory, exist_ok=True)
    
    for i in range(num_files):
        cnf = generate_cnf(num_vars, num_clauses)
        write_cnf_to_file(num_vars, num_clauses, cnf, f"{directory}/test_{i}.txt")
    print("Random CNF problems generated and written to", directory)
