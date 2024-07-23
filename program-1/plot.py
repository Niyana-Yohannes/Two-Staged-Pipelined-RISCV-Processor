import subprocess


d_missrate = []
i_missrate = []
cache_size = []
cache_params = []

for i in range(3,20):
    B = str(2**i)

    for j in range(20):
        S = str(2**j)

        for z in range(4):
            W = str(2**z)

            i_cache = "--ic="+S+":"+W+":"+B
            d_cache = "--dc="+S+":"+W+":"+B
            result = subprocess.run(["spike", "--isa=rv32i", i_cache, d_cache, "/opt/riscv/riscv32-unknown-elf/bin/pk", "program"], capture_output=True)
            result_str = str(result.stdout)
            result_arr = result_str.split("\\n")
           
            for res in result_arr:
                if "D$ Miss Rate: " in res:
                    d_missrate_arr = res.split()[-1] #Gets the miss rate
                    d_missrate_float = float(d_missrate_arr[:-1]) #Removes the %
                    d_missrate.append(d_missrate_float) 
                if "I$ Miss Rate: " in res:
                    i_missrate_arr = res.split()[-1] #Gets the miss rate
                    i_missrate_float = float(i_missrate_arr[:-1]) #Removes the %
                    i_missrate.append(i_missrate_float) 

            cache_params.append([int(S), int(W), int(B) ])
            cache_size.append(int(B)*int(S)*int(W))

d_minimized = []
i_minimized = []
for i in range(len(cache_size)):
    mem_cost = 0.1+0.0001*cache_size[i]
    d_AMAT = 1 + 10*d_missrate[i]
    i_AMAT = 1 + 10*i_missrate[i]
    d_minimized.append(mem_cost*d_AMAT)
    i_minimized.append(mem_cost*i_AMAT)

d_final_minimized = min(d_minimized)
d_final_minimized_index = d_minimized.index(d_final_minimized)
d_final_cache_param = (cache_params[d_final_minimized_index])

i_final_minimized = min(i_minimized)
i_final_minimized_index = i_minimized.index(i_final_minimized)
i_final_cache_param = (cache_params[i_final_minimized_index])

print(d_final_cache_param)
print(i_final_cache_param)
