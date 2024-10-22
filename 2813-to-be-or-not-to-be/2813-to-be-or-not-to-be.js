/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
    val = val
    return {
        toBe: (a) => {
            if (a === val) return true 
            else throw new Error("Not Equal");
        },
        notToBe: (b) => {
            if (b === val) throw new Error("Equal");
            else return true
        }
    }

};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */