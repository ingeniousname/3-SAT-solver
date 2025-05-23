def timeFileExecution(file):
    import time
    import subprocess
    start_time = time.time()
    programPath = "C:/Users/adam/Desktop/projekty/3-SAT-solver/out/build/x64-release/main.exe"
    subprocess.run([programPath, file], shell=True, check=True)
    end_time = time.time()
    return end_time - start_time

if __name__ == "__main__":
    import sys
    import os

    outfile = "output.txt"
    directory = sys.argv[1]
    times = []
    with open(outfile, "w") as f:
        for file in os.listdir(directory):
            execution_time = timeFileExecution(directory + "/" + file)
            times.append(execution_time)
            f.write(f"{execution_time:.2f}\n")
    mean = sum(times) / len(times)
    maxTime = max(times)
    variance = sum((x - mean) ** 2 for x in times) / len(times)
    stddev = variance ** 0.5
    print(mean)
    print(stddev)
    print(maxTime)