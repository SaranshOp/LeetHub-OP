/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const Trr = []
    arr.forEach((element, index)=>{
        Trr[index] = fn(element, index)
    })
    return Trr
};