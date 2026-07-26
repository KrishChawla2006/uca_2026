self.onmessage = async function () {
    try {
        const response = await fetch("https://dummyjson.com/users");

        if (!response.ok) {
            throw new Error("Failed to fetch users");
        }

        const data = await response.json();

        if (!data.users || data.users.length === 0) {
            throw new Error("No users returned");
        }

        const users = data.users.map(user => ({
            name: user.firstName + " " + user.lastName,
            active: Math.random() > 0.5
        }));

        self.postMessage({ success: true, users });

    } catch (err) {
        self.postMessage({ success: false, error: err.message });
    }
};
