bool MP1Node::UpdateMemberList(Address *addr, long heartbeat)  {
		vector<MemberListEntry>::iterator it;
		for (it = memberNode->memberList.begin(); it != memberNode->memberList.end(); it++) {
				if ((AddressFromMLE(&(*it)) == *addr) == 0) {
						if (heartbeat > it->getheartbeat()) {
								it->setheartbeat(heartbeat);
								it->settimestamp(par->getcurrtime());
								return true;
						} else {
								return false;
						}
				}
		}
		MemberListEntry mle(*((int*)addr->addr),
							*((short*)&(addr->addr[4])),
							heartbeat,
							par->getcurrtime());
		memberNode->memberList.push_back(mle);
		log->logNodeAdd(&memberNode->addr, addr);
		return true;
}
