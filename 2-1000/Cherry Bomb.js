'use strict'

function main()
{
    //const readline = require('prompt-sync')();
    let t = Number(readline());
    
    while(t--)
    {
        let arr = readline().trim().split(/\s+/).map(Number);
        let a = readline().trim().split(/\s+/).map(Number);
        let b = readline().trim().split(/\s+/).map(Number);

        let sum = -1;
        for(let i = 0; i < arr[0]; i++){
            if(b[i] != -1){
                sum = a[i] + b[i];
                break; 
            }
        }
        if(sum == -1)
        {
            a.sort((a, b) => a - b);
            print((a[0] + arr[1]) - a[arr[0] - 1] + 1);
        }
        else
        {
            let feasible = true;
            for(let i = 0; i < arr[0]; i++){
                if((b[i] == -1 && (sum - a[i] > arr[1] || sum - a[i] < 0))
                || (b[i] != -1 && b[i] + a[i] != sum)){
                    feasible = false;
                    break;
                }
            }
            if(feasible)
                print(1);
            else
                print(0);
        }
    }
}

main();