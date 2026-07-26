const worker = new Worker("worker.js");

worker.postMessage("fetchUsers");

worker.onmessage = function (event) {
    const data = event.data;

    if (data.success) {
        data.users.forEach(user => {
            console.log(`Name: ${user.name}, Active: ${user.active}`);
        });
    } else {
        console.error("Error:", data.error);
    }
};

worker.onerror = function (error) {
    console.error("Worker Error:", error.message);
};
