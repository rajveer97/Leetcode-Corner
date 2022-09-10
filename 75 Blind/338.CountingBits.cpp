/**
 * @param {number} n
 * @return {number[]}
 */
var countBits = function(n) 
{
    var arr = [];
    arr[0] = 0;
    
    for(let i=1; i<=n; i++)
    {
        var count = 0;
        var k = i;
        while( k !== 0)
        {
            if(k & 1)
                count++;
            k = k>>>1;
        }
        
        arr[i] = count;
    }
    
    return arr;
};