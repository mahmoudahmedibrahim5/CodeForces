'use strict';

function main()
{
    let n = parseInt(readline());
    let result = 0;
    for(let i = 0; i < n; i++)
    {
        let arr = readline().trim().split(/\s+/).map(Number);
        let sureAboutSolution = 0;
        for(let j = 0; j < 3; j++)
            sureAboutSolution += arr[j];
        if(sureAboutSolution >= 2)
            result++;
    }
    print(result);
}

main();
