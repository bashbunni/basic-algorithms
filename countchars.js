const NO_MATCHES = -1;

/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
/*
Attempt 1
runtime: 244ms
data: 45.6MB

var countCharacters = function(words, chars) {
    let output = NO_MATCHES;
    for (word of words) {
        let flag = true;
        let charsArr = chars.split("");
        for (c of word) {
            if (!charsArr.includes(c)) {
                flag = false; // includes a letter not contained in chars
            } else {
                charsArr.splice(charsArr.indexOf(c), 1);
            }
        }
        if (flag) {
            output += word.length;
        }
    }
    return output;
};
*/

/*
Attempt 2
runtime: 108ms
data: 46.5MB
*/
var countCharacters = function(words, chars) {
    let output = 0;
    for (word of words) {
        let validChars = chars;
        let i = 0;
        while (i < word.length && validChars.indexOf(word[i]) > NO_MATCHES) {
            validChars = validChars.slice(0, validChars.indexOf(word[i])) + validChars.slice(validChars.indexOf(word[i]) + 1);
            // validChars.splice(validChars.indexOf(word[i]), 1); using arrays takes an extra 12 ms
            i++;
        }
        if(i == word.length) {
            output += word.length;
        }
    }
    return output;
};
/*
pseudocode for A2:
==========================
while validchars has the character
- if currentchar has a match (implied) then remove it from validchars and go to next char

*/


// TESTS

console.log(countCharacters(["cat","bt","hat","tree"], "atach"));
// console.log(countCharacters(["hello","world","leetcode"],"welldonehoneyr"));
// console.log(countCharacters(["dyiclysmffuhibgfvapygkorkqllqlvokosagyelotobicwcmebnpznjbirzrzsrtzjxhsfpiwyfhzyonmuabtlwin","ndqeyhhcquplmznwslewjzuyfgklssvkqxmqjpwhrshycmvrb","ulrrbpspyudncdlbkxkrqpivfftrggemkpyjl","boygirdlggnh","xmqohbyqwagkjzpyawsydmdaattthmuvjbzwpyopyafphx","nulvimegcsiwvhwuiyednoxpugfeimnnyeoczuzxgxbqjvegcxeqnjbwnbvowastqhojepisusvsidhqmszbrnynkyop","hiefuovybkpgzygprmndrkyspoiyapdwkxebgsmodhzpx","juldqdzeskpffaoqcyyxiqqowsalqumddcufhouhrskozhlmobiwzxnhdkidr","lnnvsdcrvzfmrvurucrzlfyigcycffpiuoo","oxgaskztzroxuntiwlfyufddl","tfspedteabxatkaypitjfkhkkigdwdkctqbczcugripkgcyfezpuklfqfcsccboarbfbjfrkxp","qnagrpfzlyrouolqquytwnwnsqnmuzphne","eeilfdaookieawrrbvtnqfzcricvhpiv","sisvsjzyrbdsjcwwygdnxcjhzhsxhpceqz","yhouqhjevqxtecomahbwoptzlkyvjexhzcbccusbjjdgcfzlkoqwiwue","hwxxighzvceaplsycajkhynkhzkwkouszwaiuzqcleyflqrxgjsvlegvupzqijbornbfwpefhxekgpuvgiyeudhncv","cpwcjwgbcquirnsazumgjjcltitmeyfaudbnbqhflvecjsupjmgwfbjo","teyygdmmyadppuopvqdodaczob","qaeowuwqsqffvibrtxnjnzvzuuonrkwpysyxvkijemmpdmtnqxwekbpfzs","qqxpxpmemkldghbmbyxpkwgkaykaerhmwwjonrhcsubchs"],
// "usdruypficfbpfbivlrhutcgvyjenlxzeovdyjtgvvfdjzcmikjraspdfp"));