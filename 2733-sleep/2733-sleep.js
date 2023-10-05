/**
 * @param {number} millis
 */
 
async function sleep(millis) {
    let t = Date.now();
    await new Promise(resolve => setTimeout(resolve, millis));
    console.log(Date.now() - t);
}


/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */